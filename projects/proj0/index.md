---
title: Project 0
parent: Projects
---

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>


# AI Project 0: Graph Warmup
{: .no_toc }

1. TOC
{:toc}

*Note: This project is not supposed to be particularly challenging.  If you feel comfortable with your CS241 data structures, you should find everything in this project very straight-forward.*

For this project, you will write a program that reads a file containing a description of a graph with vertices and edges representing geographical locations. Your program will then allow the user to ask which vertices are connected to which other vertices. This project is intended to let you review the concepts involved with graphs so that you will be prepared for Project 1.

### The graph text file format

Each text file contains a description of a road network, described by **locations** and **roads.** A *location* corresponds to a single point on a map that is described by a latitude-longitude pair. A *road* is a linear connection between two locations. You will notice how in this setup, a *location* corresponds to a *vertex*, while a *road* corresponds to an *edge*.

The text file containing the road network is split into two sections. All the locations will be listed first, followed by all the roads.

Here is a sample of how a file might look:

```
location|203792386|35.1606029|-90.0020975
location|203841564|35.1582919|-90.0142355
location|1782970695|35.1509496|-89.9816435
location|203829293|35.1590589|-89.9948465
  ... more lines here ...
road|203792383|203792386|25|North Belvedere Boulevard
road|203744900|2528500275|35|North McLean Boulevard
road|203954703|203954708|45|Jackson Avenue
road|203848007|203848011|25|North Auburndale Street
  ... more lines here ...
```

Each line that begins with `location` contains the description of an intersection where one or more roads may begin or end. For each location, you are given a unique integer ID (up to ten digits), then the latitude of the location, then the longitude. The sample road networks supplied for this project contain roads in the vicinity of Memphis, so all of the latitudes and longitudes will be very close to each other (longitudes will all be close to -90 [negative means the Western hemisphere], while the latitudes are all close to 35). The four parts of each `location` line in the text file are separated by a vertical bar (`|`).

After all of the locations, the file will list all of the roads. A road is any sort of straight-line connection between two locations, covering any sort of surface a car can drive on, anything from dirt roads to interstate highways. Curved roads are approximated by multiple "road" segments, since a single "road" instance only represents a straight line. Each road is described by the identifiers of the locations that it connects, the speed limit on the road (in miles per hour), and the name of the road. The five parts of each "road" line in the text file are separated by a vertical bar (`|`). 

For example, in the file above, the road labeled Jackson Avenue connects the locations with the IDs 203954703 and 203954708, and has a speed limit of 45 miles per hour.

All roads are assumed to be bi-directional (no one-way streets), but each road is only listed once in the file. In other words, if there is a line in the file that looks like

```
road|x|y|....
```

then there will **not** be a line that looks like

```
road|y|x|....
```

even though your program should assume that you can travel in either direction between locations *x* and *y*.

There may be more than one "road" in a text file with the same name. In fact, this is quite common, for two reasons. First, a single physical road may be made of made up of multiple straight segments connecting intersections of other roads. Second, a curved road, even if it never intersects any other road, should be approximated by multiple straight segments.

Here are two sample road networks you should use to test your program: [memphis-small.txt](memphis-small.txt) [memphis-medium.txt](memphis-medium.txt)

## What your program should do

Your program **must ask** the user for a filename, **read the file**, and then **let the user type in the identifier for as many locations** as they want. For each location, **print** the roads that are directly connected to that location, along with their speed limits, names, and how many seconds it will take to drive that particular road segment. **Keep asking** the user for IDs until they type a zero, then quit.

**Efficiency**: There should not be a significant delay (< 0.5 second) between the time a user enters a location and the time your program prints back 
the roads connected to that location. This means that you should choose your graph data structures very carefully, most likely so 
common operations like adding a new location, adding a new road, or looking up what locations are connected to other locations run in expected constant 
time, or at worst, logarithmic. The "memphis-medium" network contains roughly 50,000 locations and 58,000 roads, so even linear-time 
operations will likely be too slow. The easiest way to accomplish this is to make use of a map or dictionary data structure, 
either implemented as a hash table or with some sort of tree. See the guidelines below for more information.  **Do not assume that if your program is fast enough on the "small" dataset that it will be fast enough on the "medium" dataset!**

When your program initially starts, there may be a slightly longer delay (< 5 seconds) while the road network text file is read and processed.

## Example run

```
Enter a filename: memphis-medium.txt

Enter a location ID or 0 to quit: 203744902
Location 203744902 has roads leading to:
    Location 203744903, 35 mph, North McLean Boulevard, 3.9690435922259946 seconds
    Location 203874090, 25 mph, Lyndale Avenue, 1.5289835048089322 seconds
    Location 203744900, 35 mph, North McLean Boulevard, 0.8320247723161601 seconds

Enter a location ID or 0 to quit: 204000748
Location 204000748 has roads leading to:
    Location 761690915, 35 mph, University Street, 4.6581007446819305 seconds
    Location 424696634, 35 mph, University Street, 1.3508050861544096 seconds

Enter a location ID or 0 to quit: 203804462
Location 203804462 has roads leading to:
    Location 1782962464, 25 mph, North Evergreen Street, 10.737594434783015 seconds
    Location 203848835, 25 mph, North Evergreen Street, 11.553456966352053 seconds
    Location 203659689, 25 mph, Forrest Avenue, 20.353083202256386 seconds
    Location 203804459, 25 mph, Forrest Avenue, 14.699858545615902 seconds

Enter a location ID or 0 to quit: 203821515
Location 203821515 has roads leading to:
    Location 2471207719, 35 mph, University Street, 0.27601013041370775 seconds
    Location 203785186, 25 mph, Snowden Avenue, 22.310304239490947 seconds
    Location 203874118, 35 mph, University Street, 7.353190198153813 seconds

Enter a location ID or 0 to quit: 203744908
Location 203744908 has roads leading to:
    Location 203744906, 35 mph, North McLean Boulevard, 7.441043930853628 seconds
    Location 203761725, 45 mph, Jackson Avenue, 5.616555313733091 seconds
    Location 203690459, 45 mph, Jackson Avenue, 5.655322986118794 seconds
    Location 203670571, 35 mph, North McLean Boulevard, 19.889213167091054 seconds

Enter a location ID or 0 to quit: 203744906
Location 203744906 has roads leading to:
    Location 203659729, 25 mph, Crump Avenue, 16.688407011027138 seconds
    Location 203744908, 35 mph, North McLean Boulevard, 7.441043930853628 seconds
    Location 203744904, 35 mph, North McLean Boulevard, 0.9059768372761324 seconds

Enter a location ID or 0 to quit: 0
```

## Guidelines

- You may implement this project in Java, Python, or C++.  Talk to me if you want to use another language.  You will probably want to use the same language for the next project, since it builds on this one, but that's not strictly required.

- You should implement a graph data structure to represent the road network. Locations are vertices, and the roads are edges. If you do this using the standard techniques from CS241, this program should be straightforward. 

- In Python, it is not problematic if you choose to store the unique IDs for locations as integers. You may also represent them as strings, since you never do math with them. In Java, however, the IDs are too big to be stored in an `int`, so will need to use a`string` or a `long`; whereas in C++, even a `long` is too small, so you should use a `string` or a `long long`. (yes, that exists).

- The latitudes and longitudes should be represented as floating point numbers, because you will be doing math with those in the next project. In C++ and Java, use a `double`, not a `float`.

- I highly suggest using an adjacency list of some variety to store the information, rather than an adjacency matrix. For instance, you might choose to create a `Location` data type that holds an ID and a latitude/longitude pair. You could then create a `Road` data type that holds the starting and ending IDs, the name of the road segment, and the speed limit. In Java or C++, these would be structs or classes. In Python, these could be classes (or data classes or named tuples if that's more your style), but also could be stored as (plain) tuples, dictionaries, or lists, if you are careful.

  To represent the graph itself, you will need an efficient way to look up which roads connect to a location. I suggest using a map or dictionary of some type to store this information. You will also need a way to look up the auxiliary information about a location (name, latitude, longitude) from just its numeric ID. You may want to use this idea: create two maps: (1) a map from IDs to locations, and (2) a map from IDs to the collection of roads that intersect the location corresponding to that ID. The collection of roads can be stored as a C++ vector, a Java List or Python list. In C++, this might look like:

  ```c++
  map<long long, location> locations;
  map<long long, vector<road> > roads;
  ```

  In Java, this might look like:

  ```java
  Map<Long, Location> locations;
  Map<Long, List<Road>> roads;  
  ```

  and then you can initialize those `Map`s to either `HashMap`s or `TreeMap`s, depending on which you prefer, though I think `HashMap`s make more sense here.  The `List<Road>` can either be an `ArrayList` or `LinkedList`, but I think `ArrayList` probably works just fine.

  In Python, the structures would be similar, but created as dictionaries.

- If you are using Java or C++, using the data structures libraries that come standard with Java or C++ (like those in `java.util` or C++'s `map` and `list` will make your life so much easier. Please do not write your own hash tables, arrays/vectors, or linked lists for this project. You've completed the prereqs for this course, so I expect that you could write your own if I wanted you to. Instead, use the ones that are built-in to the language you are using.

- Your output should match mine as close as you can get it.  My code is in Python; your output might be slightly different for
the number of seconds it would take to drive each road segment, depending on what programming language you pick.  However, the 
numbers should be the same to at least the first few decimal places.

## Computing the time to drive a road segment

You will notice that in order to calculate the travel time for a road segment, you will need the length of the road 
in miles as well as the speed limit. To do this from latitude and longitude coordinates, you should use this 
[code that calculates great-circle distances on a sphere](http://www.johndcook.com/python_longitude_latitude.html). (No, the earth is 
not perfectly spherical, but it’s an OK approximation.) The code given at that link returns a distance relative to the radius
of the earth; to turn it into a distance in miles, multiply the value by 3960.  You can then use the distance 
in miles combined with the speed limit of the road in miles per hour, to compute the travel time in seconds.

## At the end of the project

- As you are preparing to submit the project, please **prepare a text file** (`.txt`, pdf, or Word doc is fine) answering the following questions:
  1. What bugs and conceptual difficulties did you encounter? How did you overcome them? What did you learn?
  2. Describe whatever help (if any) that you received. Don’t include readings, lectures, and exercises, but do include any help from other sources, such as websites or people (including classmates and friends) and attribute them by name.
  3. Describe any serious problems you encountered while writing the program.
  4. Did you do any of the challenges (see below)? If so, explain what you did.
  5. List any other feedback you have. Feel free to provide any feedback on how much you learned from doing the assignment, and whether you enjoyed doing it.
- Please also add a comment at the top of your program stating **your name** and **a pledge that you have followed the honor code and collaboration policy** for this project.  This can be as simple as writing "*I have neither given nor received unauthorized aid on this program.*"  You can find the collaboration policy on the syllabus.
- Remember, projects will be graded not only on correctness, but also appropriateness and efficiency of the algorithms you choose, and on coding style.

## Submission instructions

To submit, upload **all of your program files** to canvas, including **your name and honor pledge**, and **ensure that your code satisfies the efficiency requirements**.  Make sure to also submit your **answers to the post-project questions**

Before submitting, make sure that you've included all the requirements for this project!  You can double-check by searching this page (ctrl+f or command+f) for **'must'** and **'efficiency'**; important details related to the assignment are also highlighted for your convenience.

## Additional information and hints

- The order of the roads printed for each location entered does not matter in your output.

- Python and Java both have `split` methods for strings, but C++ does not, so you can use this code if you want: 

  ```c++
  vector<string> split(const string &s, char delim)
  {
    stringstream ss(s);  // this requires #include <sstream>
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
      elems.push_back(item);
    }
    return elems;
  }
  ```

## Challenges

From time to time, I will offer “challenge problems” on assignments. These problems are designed to have little (but some) impact on your grade whether you do them or not. You should think of these problems as opportunities to work on something interesting and optional, rather than a way to raise your grade through “extra credit.”

For project 0, there are no challenges.  :(


## Extra details about how this data was generated

All of the files were created by downloading data from OpenStreetMap. I wrote a program to guess the speed limits based on the OpenStreetMap data for roads that didn't have speed limits encoded in the data, so some of the speeds probably aren't correct in reality.
