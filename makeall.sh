ARGS=$1
make $ARGS
cd antiword-0.37
make $ARGS
cd ../zxpdf-3.03
make $ARGS
cd ../docxextract
make $ARGS
cd ../zsphinx/src
make clean
make $ARGS
