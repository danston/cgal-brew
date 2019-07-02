#!/bin/bash

tar czf cgal-examples-4.14.tar.gz cgal-examples-4.14

# tar --exclude='./.git' --exclude='./make-package.sh' --exclude='./README.md' -zcvf "cgal-examples-4.14.tar.gz" .