require('dotenv').config();
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const app = express();

app.use(cors());
app.use(express.json());

mongoose.connect(process.env.MONGO_URI)
  .then(() => console.log('✅ Connected to MongoDB'))
  .catch(err => console.error('❌ MongoDB connection error:', err));

app.get('/', (req, res) => {
  res.send('Poetry backend is running 🎭');
});

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`🚀 Server is running on http://localhost:${PORT}`);
});

const authRoutes = require('./routes/auth');
app.use('/api/auth', authRoutes);

const verifyToken = require('./middleware/authMiddleware');

app.get('/api/protected', verifyToken, (req, res) => {
  res.json({ message: `Welcome, user ${req.user.userId}` });
});

const poemRoutes = require('./routes/poems');
app.use('/api/poems', poemRoutes);