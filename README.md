# Tit-Tac-Toe
A simple game of Tic Tac Toe made in C++. This program makes use of the SDL2 library

Here we have a simple Tic Tac Toe program. Let me take you through the process.
![alt text](https://cdn.discordapp.com/attachments/375398124820103172/1020091130337042482/LogoScreen.png)

At the moment we only have two options. Start the game or Exit. We'll be starting the game.
![alt text](https://cdn.discordapp.com/attachments/375398124820103172/1020092740782018660/Screenshot_1588.png)

In classic Tic Tac Toe fashion, we start off 6 empty squares. It's our turn and we play as X, let's put an X in the middle of the board

![alt text](https://cdn.discordapp.com/attachments/375398124820103172/1020092741193052230/Screenshot_1589.png)

As you can see, when we place our X down, the computer places a O somewhere. We continue this process until we get a winner

![alt text](https://cdn.discordapp.com/attachments/375398124820103172/1020092741545361458/Screenshot_1590.png)
![alt text](https://cdn.discordapp.com/attachments/375398124820103172/1020092741918670959/Screenshot_1591.png)

Let's go into a bit more detail about this project

# What's the point of this project?
There are 3 main goals I wanted to achieve with this project.

1. **To make a video game.** While it is a timeless game, I wanted to get an understanding of overall structure that an object oriented video game might have. This meant incorporating images rather than using text or built in interfaces, as well as audio and accounting for player input. These are the kind of things that are unique to video games and I wanted a better understanding of how to designa round these.

2. **To create a relatively large object oriented project.** This isn't the biggest project out there however this project has enough moving parts that I had to pay attention to the creation of objects, where they are and passing variables between different files. I don't necessarily think that treating each Tile in Tic Tac Toe as its own object is necessarily the best approach but I do think doing it that way gave me some more insight on managing objects and ultimately I think it works well.

# TO DO
There are a couple of things I would like to add to the project....

- Proper comments and documentation. There are a couple of scattered comments that I need to clear up and I should document he overall process more
- Get rid of redundant values. There are some variables and methods that are unusued 
- Incoporate loop into main game. This way the game will look so long as you don't exit it out by clicking the X button on the window
- **Add music**. This is an important one and will be done soon
- 2 Player mode. Right now it's just a fight with the computer but a 2 player mode will be added soon
- Hard Mode. Things are more fun when they're a bit hard. Right now it's pretty hard to lose to the AI so I will consider figuring out a way to make things harder without making them impossible

