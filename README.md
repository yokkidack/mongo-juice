# mongo juice


##### _"This is simple downloader of all your mongo db data"_
----

![logo][logo]

[logo]:/diz/logo-small.png 

[comment]: # (how to add text on the same level as img? TODO: that thing)

### How it works:

~~~
   (1.)                   (4.)          (2.)
       +-----------+       +----------+  +---------+
       |           +-----> |          |  |         |
       |  mongoDB  |       |  mongod  |  |  mongo  |
       |           | <-----+          |  |         |
       +--+--+--+--+       +-----+--+-+  +---------+
          |  |  |                ^  |
     +----+  |  +----+           |  |
(1.1)|       |       |           |  |
  +-----+ +--+--+ +--+--+        |  |
  |     | |     | |     |        |  |
  | db0 | | db1 | | db2 |        |  |        (3.)
  |     | |     | |     |        |  |         +-------------+
  +-----+ ++-+-++ +-----+        |  +-------> |             |
           | | |                 |            | mongo_agent |
      +----+ | +-------+         +------------+             |
(1.2) |      |         |                      +-------------+
 +----+--+ +-+-----+ +-+-----+               (5.)
 |       | |       | |       |                +-------------+
 | coll0 | | coll1 | | coll2 |                |             |
 |       | |       | |       |                |    local    |
 +-------+ +-------+ +---+---+                |             |
                         |                    +-+-----------+
                         |                      ^
                         +----------------------+

~~~
[comment]: # (use http://asciiflow.com to edit scheme)

## How to build it:

* Quick build mongo-agent with default options:
    
exequte ```quick-start``` :

~~~
$ ./quick-start
~~~

* Build tests:

~~~
$ cmake -DBUILD_TESTS=ON --target tests-d
$ make
$ ./tests-d
~~~

* Build `mongo-agent` with castom args:

~~~
$ cmake --target mongo
$ make
$ ./mongo --db=<datebase name> --coll=<collection name> --path=<path to save files>
~~~

use ```--help``` for full list of arguments