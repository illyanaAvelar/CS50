const mongoose = require('mongoose');

const poemSchema = new mongoose.Schema({
  title:     { type: String, required: true },
  text:      { type: String, required: true },
  category:  { type: String },
  createdBy: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
  likes:     [{ type: mongoose.Schema.Types.ObjectId, ref: 'User' }],
  comments:  [
    {
      text:     String,
      author:   { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
      username: String,
      date:     { type: Date, default: Date.now }
    }
  ],
  createdAt: { type: Date, default: Date.now }
});

module.exports = mongoose.model('Poem', poemSchema);