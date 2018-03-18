# Project 3 - Document_Handling_System

### DataStructures used HashTable, Queue, Trie  (Not using STL's)

#### Output:

```
                                  Welcome to my Document Handling System
                                 ======================================
    Spell Check Feature
    -------------------
    Reading dictionary.txt into the Trie ....

    Reading TobeSpellChecked.txt ....

   Incorrect Spelled words:
   ------------------------
    -> feture
    -> keyy
    -> muss

    Word Suggest Feature
    --------------------
    Suggestions:
    ------------
    feture
      -> feature
      -> fixture
      -> future
      -> gesture
      -> lecture
      -> mature
      -> metre
      -> nature
      -> texture
      -> venture
    keyy
      -> deny
      -> hey
      -> kelly
      -> kenny
      -> kenya
      -> kerry
      -> key
      -> keys
      -> levy
      -> rely
      -> rey
    muss
      -> mass
      -> mess
      -> miss
      -> moss
      -> mugs
      -> mus
      -> muse
      -> must
      -> russ
      -> uss

    Auto Correct Feature
    --------------------

    Reading dictionary.txt Please wait ....
    Trie was populated. Total notes created were 47367
    Enter a prefix for Auto-Completion. Enter quit to exit.
    kel
kelly
keller
kelley
kellogg
kelkoo
    Next prefix: wer
were
werner
    Next prefix: jus
just
justice
justin
justify
justification
justified
    Next prefix: quit

    Document Retrieval Feature
    --------------------------
    Processing all Files please wait ...
    Processed all files !!!
    Query Mechanism started ...
    Enter number of queries:
    4
    Enter word #1 :
    sun
        Did you mean "an" ?
        Found in 3 files:
    1.txt  2.txt  3.txt
    Enter word #2 :
    upstream
        Found in 2 files:
    0.txt  1.txt
    Enter word #3 :
    market
        Found in 2 files:
    2.txt  3.txt
    Enter word #4 :
    result
        Found in 2 files:
    2.txt  3.txt

     Set of all Filenames queried:
    0.txt     1.txt     2.txt     3.txt

Press any key to continue . . .
