import { useState } from "react";

export const Header = () => {
  const [search, setSearch] = useState("");
  const [category, setCategory] = useState("all");

  return (
    <header className="w-full bg-orange-300">
      <div className="max-w-7xl mx-auto px-4 py-4 flex flex-col sm:flex-row items-center justify-between gap-4">
        <h1 className="text-2xl font-semibold text-white">poetry website</h1>
        
        <div className="flex flex-col sm:flex-row gap-4 items-center w-full sm:w-auto">
          <input
            type="text"
            value={search}
            onChange={(e) => setSearch(e.target.value)}
            placeholder="Search poems..."
            className="px-4 py-2 rounded-2xl bg-orange-50 border border-rose-200 focus:ring-2 focus:ring-rose-300 focus:outline-none w-full sm:w-64 transition"
          />
          
            <div className="px-4 py-2 rounded-2xl bg-orange-50 border border-rose-200 focus:ring-2 focus:ring-rose-300 focus:outline-none transition">
              <select
                value={category}
                onChange={(e) => setCategory(e.target.value)}
                className="pr-4 bg-orange-50 border-none outline-none"
              >
                <option value="all">All Categories</option>
                <option value="love">Love</option>
                <option value="nature">Nature</option>
                <option value="life">Life</option>
              </select>
            </div>
        </div>
      </div>
    </header>
  );
};
