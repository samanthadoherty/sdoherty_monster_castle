# Game Design Document

----

## Monster Kingdom: Quest for Gold
Monster Kingdom: Quest for Gold is a game in which the user's goal is to collect as many pots of gold 
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
but there is not penalty if the user runs into it; it simply serves as an obstacle.

The user maneuvers himself using the up, down, left, and right arrows on the keyboard. The user can also 
collect a slowly moving piece of candy for 100 points to rack up easier points. Once collected, the piece of
candy will reappear at a random other location to be collected again in the future if the user desires.
If the user runs into the dynamite, which will move randomly yet slowly, the game will automatically end 
and the user will end up with however many points he or she has collected thus far. 

The user will have three lives to start with. Gameplay only ends when the user loses his last life or runs
into the dynamite. The goal is to get the most amount of points by the end of the game, which can be done 
by collecting candy and/or the pot of gold. The game will speed up as gameplay goes on, until it becomes
virtually impossible to play.



The following is a list of all objects in the game.

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

