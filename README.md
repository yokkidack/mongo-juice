# mongo juice


##### _"This is simple downloader of all your mongo db data"_
----
[comment]: # ( spetial thanks to Varvara Isaeva, check her out 
            https://www.behance.net/varyaisaevab9b5)
                
[comment]: # ( so, i think its time i answer age-old two-days-old question: why 
mongo juice? so mongo ~ mango, mango is a fruit, fruits are mostly in form of 
juice, my program gets mongo contents out of mongodb, like kid does when drinks 
juice, im lonely, please help)


![logo][logo]


[comment]: # (how to add text on the same level as img? TODO: that thing)

### Table of Contents

<pre>
<a href="#overview">Overview</a>
<a href="#how-it-works">How it works</a>
<a href="#how-to-build-it">How to build it</a>
<a href="#licence">Licence</a>
</pre>

[to the top](#table-of-contents)
 
### Overview

I made this tool as a tearm project for TIMP class in 2018-2019. Mongo-juice is a simpla and small tool to download/replicate mongoDB data to local directory

### How it works:

[comment]: # (use http://asciiflow.com to edit scheme)

[comment]: # (translate these texts)

```
+----------------------------------------------------------------------+
|                                                                      |
| +-------+                                          +---------------+ |
| |mongoDB+---------> mongo-agent             +----> |local directory| |
| +-------+    +-------------------------+    |      +---------------+ |
|              |                         |    |                        |
|              | replicating-mongo-agent +----+                        |
|              |                         |           +----+            |
|              | counting-mongo-agent    +---------> |info|            |
|              |                         |           +----+            |
|              +-------------------------+                             |
|                                                                      |
+----------------------------------------------------------------------+


```

1. MongoDB

    Система баз данных с открытым исходным кодом на основе документов. 
    «MongoDB» происходит от слова «огромная» из-за способности базы данных 
    легко масштабироваться и хранить очень большие объемы данных. MongoDB 
    хранит документы в коллекциях в базах данных.
    
```
+-----------------------------------------+
|                                         |
| +---------+                             |
| | mongoDB |                             |
| +---+-----+                             |
|     |                                   |
|     |  +------------+    +------------+ |
|     +> |data base 1 +-+> |collection 1| |
|     |  +------------+ |  +------------+ |
|     |     ...         |     ...         |
|     |  +------------+ |  +------------+ |
|     +> |data base N | +> |collection N| |
|        +------------+    +------------+ |
|                                         |
+-----------------------------------------+
```
    
На схеме показанно: MongoDB хранит в себе `базы данных`, дазы данных хранят в себе `коллекции`

1.1 База данных (database)
    
    Физический контейнер для коллекций. Каждая 
    база данных получает свой набор файлов в файловой 
    системе. Один сервер MongoDB обычно имеет несколько
    баз данных.
    
1.2 Коллекция (collection)
    
    Группировка документов MongoDB. Коллекция является 
    эквивалентом таблицы RDBMS. Коллекция существует в
    одной базе данных. Коллекции не приводят в исполнение 
    график. Документы в коллекции могут иметь разные поля. 
    Как правило, все документы в коллекции имеют 
    аналогичное или связанное назначение.

2. Mongo

    Оболочка MongoDB. Процесс mongo запускает оболочку 
    MongoDB как демон, подключенный к экземпляру mongod 
    или mongos. Оболочка имеет интерфейс JavaScript.
    
3. mongo_agent

    Программа-агент для работы с MongoDB

4. Mongod

    Сервер базы данных MongoDB. Процесс mongod запускает 
    сервер MongoDB как демон. Сервер MongoDB управляет 
    запросами данных, форматирует их и управляет фоновыми 
    операциями.
    
5. Локальное хранилище 

[to the top](#table-of-contents)

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

[to the top](#table-of-contents)

# Licence
```
The MIT License (MIT)

Copyright (c) 2019 Roshchin Igor @yokkidack mosgreyday@gmail.com
Copyright (c) 2018 Varvara Isaeva (logo) https://www.behance.net/varyaisaevab9b5

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
[logo]:/diz/logo-small.png 
