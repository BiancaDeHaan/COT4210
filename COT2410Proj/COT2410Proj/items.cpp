#include "Header.h"

void TextAdventure::loadItems() {
	//manually loading in items to the list of items in the text adventure

	Item trophy = Item("trophy", "You approach the daunting wall of trophies and plaques.  \n"
		"Car shows, Boat shows, and accolades for Fairsley Pharmaceuticals.  \n"
		"First place in every competition, Ben Fairsley was a competitive man.  \n"
		"On each and every trophy that lists more than the first place contender, you can see the name “Alex Hughes” in second place.", true);

	Item bookshelf = Item("bookshelf", "Of all the fine-looking books on this neatly arranged bookshelf, one stands out:  \n"
		"A recently purchased copy of “Mars for dummies.”  You open the book, and a [Photo] falls out", false);

	Item photo = Item("photo", "It’s a photo that appears to be taken from high above a beach, perhaps from a hotel room, of two men holding hands lying on a couple of beach chairs, facing the sunset.  \n"
		"The photo is blurry, so you can’t tell exactly who they are.  You flip the photo, on the back written in pen are the words, “I’d like to renegotiate our terms.  -JSync” ", true);

	Item desk = Item("desk", "You approach the desk.  It’s a deep reddish brown, with several drawers on each side.\n"
		"Rifling through the drawers one by one, you find nothing of note until you attempt to open one drawer, only for it to jam.\n"
		"You examine the jam to discover it’s a crumpled up ball of paper, a[Notice] of resignation.", false);

	Item notice = Item("notice", "A letter of resignation from Evelyn Garcia, the Fairsleys’ maid.  It seems to have been torn in half and stuffed into this drawer in a fit", true);

	Item bedstand = Item("nightstand", "You examine the Nightstand for clues.  \n"
		"On top of it lies a lamp and an alarm clock. There’s one drawer.  \n"
		"You open the drawer to see a nothing inside but a [Watch].", false);

	Item watch = Item("watch", "A watch with the name “T. Park” engraved on the back.  \nWhat could this be doing in the nightstand?", true);

	itemsInGame.push_back(trophy);
	itemsInGame.push_back(bookshelf);
	itemsInGame.push_back(photo);
	itemsInGame.push_back(desk);
	itemsInGame.push_back(notice);
	itemsInGame.push_back(bedstand);
	itemsInGame.push_back(watch);


	//Other type of item
	Item office = Item("office", "You enter the office of Ben Fairsley.  \n"
		"It’s very lavish, he has a small [bookshelf] of leather-bound books, and the whole room smells of rich mahogany due to a rather ornate [desk] in the middle of the room.)", false);
	Item bedroom = Item("bedroom", "You enter the bedroom of Mr. and Mrs. Fairsley.   \nThe bed is, of course, unmade, as Ben Fairsley was found there this morning.  \nNext to the bed is a [Nightstand].)", false);
	itemsInGame.push_back(office);
	itemsInGame.push_back(bedroom);

}