# Game Design Document

----

## Monster Castle: Quest for Gold
Monster Castle: Quest for Gold is a game in which the user's goal is to collect as many pots of gold 
and pieces of candy as possible. The catch is the user must dodge monsters, which cost the user one life,
and dynamite, which--if run into--will cause the game to end, regardless of how many lives are left. The 
goal of the game is to collect the most amount of points before the user's lives run out or the game is 
terminated by running into dynamite.

### General Gameplay
To begin the game, the user will always start in the bottom left corner of the board. The pot of gold will 
be stationary at the top right corner of the board, worth five hundred points if collected. The user will be
relocated to the starting position, the bottom left corner, every time he collects the pot of gold.
Two monsters will be "guarding" the gold, one moving vertically back and forth and the other, horizontally. 
The user loses a life if he runs into either of these monsters. A wall will also be moving horizontally, 
but there is no penalty if the user runs into it; it simply serves as an obstacle.

The user maneuvers himself using the up, down, left, and right arrows on the keyboard. The user can also 
collect a slowly moving piece of candy for 100 points to rack up easier points. Once collected, the piece of
candy will reappear at a random other location to be collected again in the future if the user desires.
If the user runs into the dynamite, which will move randomly yet slowly, the game will automatically end 
and the user will end up with however many points he or she has collected thus far. 

The user will have three lives to start with. Gameplay only ends when the user loses his last life or runs
into the dynamite. If the user loses a life, he will be reset at the starting position (bottom left corner)
The goal is to get the most amount of points by the end of the game, which can be done by collecting candy 
and/or the pot of gold. The game will speed up as gameplay goes on, until it becomes virtually impossible 
to play.


###Objects
**The following is a list of all objects in the game:**

  1. User [not counted as one of the five objects]: can be moved using the up, down, left, and right arrow 
    keys on the keyboard. Will be represented by the following image (which will be shrinked to fit game board scale):
  
  ![alt text](http://www.pixeljoint.com/files/icons/full/warrior_single_fn.gif "Player Icon")
  2. Horizontal Monster [Object 1 of 5]: When this monster appears, it will start to **move** horizontally back and forth
      at a location a few rows away from the stationary the pot of gold. If the user runs into the monster, the user
      will lose a life. This monster will be represented by the following image:

      ![alt text](http://files.softicons.com/download/animal-icons/monster-icons-by-spoongraphics/png/24x24/Green-Monster.png "Green Monster")
  3. Vertical Monster [not counted as one of the five objects since it is similar to #2]: When this monster appears,
    it will **move** vertically up and down, a few columns away from the stationary pot of gold. Just like with the
    horizontal monster, if run into, it will cost the user one life. Together with the horizontal monster, it essentially
    "guards" the pot of gold and the user must time his moves perfectly to get past both monsters. The monster will be
    represented by the following image:

    ![alt text](http://files.softicons.com/download/animal-icons/monster-icons-by-spoongraphics/png/24x24/Blue-Monster.png "Blue Monster")
  4. Pot of Gold [Object 2 of 5]: The pot of gold will appear in the very top right corner of the screen, where it will
     remain **stationary** the entire game. Every time the user passes over it, 500 points will be added to the user's score. The user
     will also reappear at the bottom right corner, his starting point (this is to prevent the user from continually
     passing over the gold to rack up the points). This object will be represented by the following image, which will
     obviously be resized to fit the game board scale:

     ![alt text](http://www.allfreelogo.com/images/vector-thumb/pot-of-gold-prev114054467117I6sP.jpg "Pot of Gold")
  5. Candy [Object 3 of 5]: The candy will randomly appear and **move** randomly around the board. If the user runs into
     it, the user will gain 100 points. The candy will then reappear in a random other location to prevent the user from
     easily running into the candy again. The candy will be represented by this icon:

     ![alt text](http://www.clker.com/cliparts/9/c/2/c/11949863201080446347candy_02.svg.thumb.png "Candy")
  6. Wall [Object 4 of 5]: This object will appear and **move** horizontally back and forth. The user cannot occupy the
     space where the wall resides, nor can he pass right through it in any manner. Its only purpose is to create an
     obstacle to the user's movement, as the user does not lose anything if he gets close to it. The wall will be
    represented by the following icon: 
    
    ![alt text](http://cdn1.iconfinder.com/data/icons/Siena/48/wall%20red.png "Wall")

  7. Dynamite [Object 5 of 5]: This object will appear and **move** randomly. If the user runs into it, the game will
     immediately end, regardless of how many lives the user has left. The user will receive the score they have at the
     moment they ran into the dynamite. This should not happen too often because the dynamite will be the slowest moving
     object. The dynamite will be represented by the following image:
     
     ![alt text](http://tutorialqueen.com/wp-content/uploads/2009/04/photoshop-dinamite-logo-stock-photo28-thumb.jpg "Dynamite")
     
###Graphical User Interface
The following will show how the game will look at different stages: 

  1. On the opening screen, the user will be able to enter his or her name and then press `Start` (the `Start` button can only
     be pressed if the user has entered something in the text box. The user alternatively has the option to click a push 
     button called `How to Play` that creates a pop up window detailing how to play the game (see number 2). The 
     image below illustrates this layout:
     
     ![alt text](http://i1350.photobucket.com/albums/p776/samdoh1121/startmenu_zps056f8e3f.png "Start Menu")
     
  2. Pop-up window showing how to play the game:
  
     ![alt text](http://i1350.photobucket.com/albums/p776/samdoh1121/howtoplay_zps6d288457.png "How to play")
     
  3. After the user has pressed `Start`, a new scene will appear. On the top strip will be a `Pause` button on 
     the far left and a `Restart` button on the far right that can be pushed at any time. In between these will be the user's score, followed by
     the number of lives he has left. Below that will be the actual game play. Finally, the bottom strip will have a `Quit`
     button and the user's name. This is shown below:
     
     ![alt text](http://i1350.photobucket.com/albums/p776/samdoh1121/gameplay_zps4b35e9e6.png "Game Play") 
  
  4. When the game ends, the user will be taken to a new screen that says Game Over at the top. Below that, it will show the
     user's name, and below that will be the word Score: followed by the user's score. Below all of that will be a button that
     says `Play again?` which will restart the game. This is shown here:
     
     ![alt text](http://i1350.photobucket.com/albums/p776/samdoh1121/gameover_zps67ab6398.png "Game Over") 
     


