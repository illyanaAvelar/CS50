const express = require('express');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const User = require('../models/User');

const router = express.Router();

router.post('/register', async (req, res) => {
  try {
    const { username, email, password, isAdmin } = req.body;

    const hashedPassword = await bcrypt.hash(password, 10);

    const user = new User({
      username,
      email,
      password: hashedPassword,
      isAdmin: isAdmin || false,
    });

    await user.save();
    res.status(201).json({ message: 'User created 🎉' });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

router.post('/login', async (req, res) => {
  try {
    const { email, password } = req.body;

    const user = await User.findOne({ email });
    if (!user) return res.status(400).json({ error: 'Invalid credentials' });

    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) return res.status(400).json({ error: 'Invalid credentials' });

    const token = jwt.sign(
      { userId: user._id, isAdmin: user.isAdmin },
      'secretKey',
      { expiresIn: '2h' }
    );

    res.json({ token, userId: user._id, isAdmin: user.isAdmin });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
