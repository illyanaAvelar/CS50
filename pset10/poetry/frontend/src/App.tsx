import { AboutCard } from "./components/AboutCard";
import { Header } from "./components/Header/Header";
import { PoetryCard } from "./components/PoetryCard";
import { SubscribeCard } from "./components/SubscribeCard";

function App() {
  return (
    <div className="bg-orange-200 min-h-screen">
    <Header />
    <main className="max-w-6xl mx-auto p-4 grid grid-cols-1 md:grid-cols-3 gap-6 mt-6">
      <div className="md:col-span-2">
        <PoetryCard title="Whispers of the Wind" text={`The wind whispered
Through the trees,
Telling secrets
On the breeze.`} />
        <PoetryCard title="Silent Moon" text={`The moon watches
Silently at night,
Guarding our dreams
With soft light.`} />
<PoetryCard title="Silent Moon" text={`The moon watches
Silently at night,
Guarding our dreams
With soft light.
The moon watches
Silently at night,
Guarding our dreams
With soft light.`} />
<PoetryCard title="Silent Moon" text={`The moon watches
Silently at night,
Guarding our dreams
With soft light.
`} />
<PoetryCard title="Silent Moon" text={`The moon watches
Silently at night,
Guarding our dreams
With soft light.`} />
      </div>
      <div>
        <AboutCard />
        <SubscribeCard />
      </div>
    </main>
  </div>
  );
}

export default App;
