# Veridian
A 2D video game engine focused on optimizing the memory structure for simulation games using an entity-component-system architecture.

This is a passion project that I'm working on in my free time to learn more about game engine structure, graphics programming, and practice my C++ skills.
I'm utilizing Simple Directmedia Layer 2 (SDL2) as my interface with the graphics API. I've been working on this project on-and-off for about a year, but
most of my work has been tinkering with various implementations of a basic program structure to wrap my head around the entity-component-system with very
little actual game engine programming. With a decent understanding of what I'd like to accomplish now, I'm working on making an actual functional prototype.

Currently, the game engine consists of a very basic set of components and a single system. Those are position and sprite components, and a display system. Nonetheless, this is enough to fully implement an ECS structure; an EntityManager manages components and can create new entities and register them with components, and the display system can operate on the components. In this case, the display system operates on position and sprite components to render 2d sprites on the screen. 

This entire system is encapsulated in World objects, which store an entitymanager and a set of systems. The long-term idea behind this is that Worlds will be quite versatile and can be used to create everything from a main menu system to game levels to dimensions of an open world, and can generally be added or removed without affecting other worlds.

Author: Erik Stacey

Updated: 29 March 2023
