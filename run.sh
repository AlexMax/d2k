#!/bin/sh

export LIBGL_ALWAYS_SOFTWARE=1
CMD="cbuild/doom2k -nomonsters -nomouse"

# gdb -ex run --args $CMD
# CPUPROFILE=cpu.prof cbuild/doom2k
# cbuild/doom2k -skill 4 -warp 1 -file sunder.wad -warp 6
# cbuild/doom2k -playdemo DEMO1
cbuild/doom2k -skill 4 -warp 1
# cbuild/doom2k -playdemo DEMO1

