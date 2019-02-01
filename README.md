# mongo juice


##### _"This is simple downloader of all your mongo db data"_
----

![logo][logo]

[logo]:/diz/logo-small.png 

[comment]: # (how to add text on the same level as img? TODO: that thing)

### Table of Contents

<pre>
<a href="#overview">Overview</a>
<a href="#how-to-build-it">How to build it</a>
<a href="#licence">Licence</a>
</pre>

[![top] Goto Top](#table-of-contents)
 
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

[![top] Goto Top](#table-of-contents)

# How to build it

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


[top]: https://muflihun.github.io/easyloggingpp/images/up.png?v=4

[![top] Goto Top](#table-of-contents)

# Licence
```
The MIT License (MIT)

Copyright (c) 2019 @yokkidack <Igor Roshchin>
Copyright (c) 2018 Varvara Isaeva (logo)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```