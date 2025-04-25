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
    const poems = await Poem.find().populate('createdBy', 'username');
    res.json(poems);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
