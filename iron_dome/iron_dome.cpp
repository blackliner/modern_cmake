#include <aero/aero.h>
#include <SFML/Graphics.hpp>

// This is the main C++ program- Duh!
// It is where our game starts from
int main()
{
    // Make a window that is 800 by 200 pixels
    // And has the title "Iron dome"
    sf::RenderWindow window(sf::VideoMode(800, 640), "Iron dome");

    // Create a "Text" object called "message". Weird but we will learn about objects soon
    sf::Text message;

    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Set the font to our message
    message.setFont(font);

    // Make it really big
    message.setCharacterSize(20);

    // Choose a color
    message.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;
    double fps{};

    aero::KinematicObject some_mass;
    some_mass.setMass(1.0);
    some_mass.SetInertia(1.0);
    some_mass.setAcceleration({-9.81, 5.0});
    some_mass.setVelocity({100, 50});

    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        const auto dt_ms = dt.asMilliseconds();

        // The next 6 lines of code detect if the window is closed
        // And then shuts down the program
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Clear everything from the last run of the while loop
        window.clear();

        const double fps_factor = 1000.0 / (1000.0 + dt_ms);
        fps = fps_factor * fps;
        if (dt_ms > 0)
        {
            fps += (1.0 - fps_factor) * 1000.0 / dt_ms;
        }

        // Assign the actual message
        message.setString(std::to_string(fps));

        // Draw our message
        window.draw(message);

        some_mass.step(std::chrono::milliseconds(dt_ms));

        const auto pos = some_mass.position();
        // sf::Vertex line[] =
        //     {
        //         sf::Vertex(sf::Vector2f(pos[0] + 100, pos[1])),
        //         sf::Vertex(sf::Vector2f(pos[0], pos[1] - 100))};

        // shape.setFillColor(sf::Color(150, 50, 250));
        // window.draw(line, 20, sf::Lines);

        sf::CircleShape shape(50);

        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));

        const auto mouse_position = sf::Mouse::getPosition(window);
        const auto local_pos = window.mapPixelToCoords(mouse_position);

        // local_pos = {0.0F, 1.0F};
        // local_pos = sf::Vector2f{static_cast<float>(pos[0]), static_cast<float>(pos[1])};

        sf::Vector2f test{pos(1), pos(0)};

        shape.setPosition(test - sf::Vector2f{shape.getRadius(), shape.getRadius()});

        window.draw(shape);

        // Draw our game scene here
        // Just a message for now

        // Show everything we just drew
        window.display();
    } // This is the end of the "while" loop

    return 0;
}
