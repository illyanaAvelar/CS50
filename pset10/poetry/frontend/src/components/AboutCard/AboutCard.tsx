import profileImage from '../../assets/profile.png'
import { FaInstagram, FaFacebookF, FaEnvelope } from 'react-icons/fa'

export const AboutCard = () => {
    return (
      <div className="bg-orange-50 shadow rounded-2xl p-6 flex flex-col gap-4">
        <h3 className="text-lg font-semibold text-rose-800 mb-4">About Me</h3>
        <img
            src={profileImage}
            alt="Profile"
            className="h-64 w-42 rounded-full object-cover mx-auto shadow-md"
        />
        <p className="text-gray-700 text-sm mb-4 text-center">
          I'm a passionate poet who loves to share thoughts, emotions, and beauty through words. Follow my journey.
        </p>
        <div className="flex justify-center gap-4 text-rose-600 text-xl">
        <a href="https://www.instagram.com" target="_blank" rel="noopener noreferrer">
        <FaInstagram className="w-6 h-6 text-orange-300 hover:text-orange-400 transition" />
        </a>
        <a href="mailto:someone@example.com">
            <FaEnvelope className="w-6 h-6 text-orange-300 hover:text-orange-400 transition" />
        </a>
        <a href="https://www.facebook.com" target="_blank" rel="noopener noreferrer">
            <FaFacebookF className="w-6 h-6 text-orange-300 hover:text-orange-400 transition" />
        </a>
        </div>
      </div>
    );
  };
  