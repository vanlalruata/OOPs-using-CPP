#include <iostream>
#include <string>
#include <memory>

/**
 * @class Media
 * @brief A base class for different types of media.
 */
class Media {
protected:
    std::string title;

public:
    Media(const std::string& t) : title(t) {}

    // A virtual destructor is essential for polymorphic base classes.
    virtual ~Media() {
        std::cout << "Media destructor for '" << title << "'." << std::endl;
    }

    /**
     * @brief A virtual function for playing the media.
     * 
     * The 'virtual' keyword creates an entry in the class's virtual table (vtable).
     * When a virtual function is called through a base class pointer, the program
     * uses the vtable to look up the correct function to call at runtime based on
     * the object's actual type (dynamic dispatch).
     */
    virtual void play() const {
        std::cout << "Playing generic media: " << title << std::endl;
    }

    /**
     * @brief A non-virtual function.
     * 
     * Calls to non-virtual functions are resolved at compile-time based on the
     * type of the pointer or reference used to call them (static dispatch).
     */
    void stop() const {
        std::cout << "Stopping media (called from Media class)." << std::endl;
    }
};

/**
 * @class Audio
 * @brief A derived class for audio media.
 */
class Audio : public Media {
public:
    Audio(const std::string& t) : Media(t) {}
    ~Audio() {
        std::cout << "Audio destructor for '" << title << "'." << std::endl;
    }

    // Override the virtual play function.
    void play() const override {
        std::cout << "Playing audio: " << title << std::endl;
    }
};

/**
 * @class Video
 * @brief A derived class for video media.
 */
class Video : public Media {
public:
    Video(const std::string& t) : Media(t) {}
    ~Video() {
        std::cout << "Video destructor for '" << title << "'." << std::endl;
    }

    // Override the virtual play function.
    void play() const override {
        std::cout << "Playing video: " << title << std::endl;
    }
};

// A helper function to demonstrate polymorphism.
void performMediaActions(const Media* mediaPtr) {
    std::cout << "--- Performing actions ---" << std::endl;
    
    // Dynamic Dispatch: The 'play' function is virtual.
    // The program looks at the actual object mediaPtr points to at runtime
    // and calls the appropriate overridden version (Audio::play or Video::play).
    std::cout << "Calling virtual function play(): ";
    mediaPtr->play();

    // Static Dispatch: The 'stop' function is not virtual.
    // The compiler sees that mediaPtr is a 'Media*' and resolves the call
    // to Media::stop at compile-time, regardless of the actual object's type.
    std::cout << "Calling non-virtual function stop(): ";
    mediaPtr->stop();

    std::cout << "------------------------" << std::endl;
}

int main() {
    // Using smart pointers for automatic memory management.
    std::unique_ptr<Media> audio = std::make_unique<Audio>("Symphony No. 5");
    std::unique_ptr<Media> video = std::make_unique<Video>("The Matrix");

    performMediaActions(audio.get());
    performMediaActions(video.get());

    std::cout << "\nExiting main. Destructors will be called automatically." << std::endl;
    return 0;
}
