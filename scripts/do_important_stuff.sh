#!/bin/bash
# Do some important stuff.
# Note: "websiteChecker" program cannot be running while we do this stuff.





##### DO NOT MAKE ANY CHANGES BELOW THIS LINE

# once we kick off this script, we want to kill all instances of the calling
# program, because it will interfere with the work that this script has to
# do (let's say that they both need to use the same serial ports)
killall -9 websiteChecker
sleep 5

# do our important stuff
touch ~/test_important_stuff

# clean up
exit 0
