#!/bin/bash

tar --exclude='./.git' --exclude='./make-package.sh' --exclude='./README.md' -zcvf "cgal-examples-4.14.tar.gz" .
shasum -a 256 /Users/monet/Documents/brew/cgal-examples/cgal-examples-4.14.tar.gz