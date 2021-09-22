# RadioTide C

This was the beginning of a C variant (built years ago back in 2014) 
that I had originally made based off of the Python RadioTide project located here:
https://github.com/nonapod/RadioTide

This project requires the following repo:
https://github.com/nonapod/libyutil

Create a lib directory at the root of this project and then clone
the *libyutil* repo into it.

To build the project, make sure you have cmake available, then 
run cmake CMakeLists.txt to generate all of the cmake files, 
including a make file. Once you've done that, run `make` and
a `RadioTide` file should appear in the bin directory if everything
worked.
