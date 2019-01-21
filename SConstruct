#!/bin/python3

def add_sources(self, sources, filetype):
    import glob
    dir = self.Dir('.').abspath
    list = glob.glob(dir + "/" + filetype)
    for f in list:
        sources.append(self.Object(f))

env = Environment()
env.__class__.add_sources = methods.add_sources

env.Append(CXXFLAGS=['-std=c++14'])

Export("env")

SConscript("#src/SCsub")
