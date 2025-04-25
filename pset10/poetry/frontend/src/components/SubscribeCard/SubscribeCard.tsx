import { useState } from "react";

export const SubscribeCard = () => {
    const [email, setEmail] = useState('');
  
    return (
      <div className="bg-orange-50 shadow rounded-2xl p-6 mt-6">
        <h3 className="text-lg font-semibold text-rose-800 mb-2">Subscribe</h3>
        <input
          type="email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}  
          placeholder="Enter your email"
          className="w-full p-2 rounded-lg border border-rose-200 mb-2"
        />
        <button className="w-full bg-orange-300 hover:bg-rose-500 text-white py-2 rounded-lg">Subscribe</button>
      </div>
    );
  };
  