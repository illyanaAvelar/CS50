const express = require('express');
const Poem = require('../models/Poem');
const verifyToken = require('../middleware/authMiddleware');

const router = express.Router();

router.post('/', verifyToken, async (req, res) => {
  try {
    if (!req.user.isAdmin) return res.status(403).json({ error: 'Admin only' });

    const { title, text, category } = req.body;

    const poem = new Poem({
      title,
      text,
      category,
      createdBy: req.user.userId,
      likes: [],
      comments: []
    });

    await poem.save();
    res.status(201).json(poem);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

router.get('/', async (req, res) => {
  try {
    const { keyword, category } = req.query;

    let query = {};

    if (keyword) {
      const regex = new RegExp(keyword, 'i');
      query.$or = [{ title: regex }, { text: regex }];
    }

    if (category) {
      query.category = category;
    }

    const poems = await Poem.find(query).populate('createdBy', 'username');

    res.json(poems);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

router.post('/:id/like', verifyToken, async (req, res) => {
  try {
    const poem = await Poem.findById(req.params.id);

    if (!poem) {
      return res.status(404).json({ error: 'Poem not found' });
    }

    const userId = req.user.userId;

    if (poem.likes.includes(userId)) {
      return res.status(400).json({ error: 'You already liked this poem' });
    }

    poem.likes.push(userId);
    await poem.save();

    res.json({ message: 'Poem liked', likesCount: poem.likes.length });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

router.post('/:id/comment', verifyToken, async (req, res) => {
  try {
    const { text } = req.body;

    if (!text) return res.status(400).json({ error: 'Comment text is required' });

    const poem = await Poem.findById(req.params.id);

    if (!poem) return res.status(404).json({ error: 'Poem not found' });

    const newComment = {
      text,
      author: req.user.userId,
      username: req.user.username,
      date: new Date()
    };

    poem.comments.push(newComment);
    await poem.save();

    res.status(201).json({ message: 'Comment added', comment: newComment });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;