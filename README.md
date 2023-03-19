# Veridian
A 2D video game engine focused on optimizing the memory structure for simulation games using an entity-component-system architecture.

This is a passion project that I'm working on in my free time to learn more about game engine structure, graphics programming, and practice my C++ skills.
I'm utilizing Simple Directmedia Layer 2 (SDL2) as my interface with the graphics API. I've been working on this project on-and-off for about a year, but
most of my work has been tinkering with various implementations of a basic program structure to wrap my head around the entity-component-system with very
little actual game engine programming. With a decent understanding of what I'd like to accomplish now, I'm working on making an actual functional prototype.

Currently, the game engine consists of a display system which can interface with world objects containing background tilemaps. The basic entity-component architecture is in place, with entities consisting of a unique integer ID. While only one datatype (a Vector2 object, containing two floats) is currently implemented, the system is sufficiently general that one can create new components just by calling a function corresponding to the desired datatype and giving it a name. Components are generally unaware of each other, and the entity manager doesn't even know what components each entity has; when doing something like acting to destroy an entity, it is left up to each component to determine if they contain data about that entity and destroy it.

The next step is to implement a basic system (of the entity-component-system), which operates on components.

Author: Erik Stacey
Updated: 18 March 2023
