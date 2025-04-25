const express = require('express');
const router = express.Router();
const Subscriber = require('../models/Subscriber');

router.post('/', async (req, res) => {
  try {
    const { name, email } = req.body;

    if (!name || !email) return res.status(400).json({ error: 'Name and email are required' });

    const existing = await Subscriber.findOne({ email });
    if (existing) return res.status(409).json({ error: 'Already subscribed' });

    const subscriber = new Subscriber({ name, email });
    await subscriber.save();

    res.status(201).json({ message: 'Subscribed!' });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
