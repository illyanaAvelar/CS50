import { useState } from 'react';

export const PoetryCard = ({ title, text }: { title: string; text: string }) => {
  const [likes, setLikes] = useState(0);
  const [comments, setComments] = useState(0);

  return (
    <div className="bg-orange-50 shadow rounded-2xl p-6 mb-6">
      <h2 className="text-xl font-semibold text-rose-800 mb-2">{title}</h2>
      <p className="text-gray-700 mb-4 whitespace-pre-wrap">{text}</p>
      <div className="flex justify-between items-center text-sm text-rose-600">
        <div className="flex gap-4">
          <button onClick={() => setLikes(likes + 1)}>❤️ {likes}</button>
          <button onClick={() => setComments(comments + 1)}>💬 {comments}</button>
        </div>
        <button>🔗 Share</button>
      </div>
    </div>
  );
};