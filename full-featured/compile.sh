#!/bin/sh

BASEDIR=$(realpath .)

compile_driver()
{
    echo "Compiling driver";
    cd $BASEDIR;
    cd applications/drivers;
    make;
}

compile_app()
{
    echo "Compiling application";
    cd $BASEDIR;
    cd applications/example_app;
    make;
}

compile_kernel()
{
    echo "Compiling kernel";
    cd $BASEDIR;
    cd kernel/stm32f412gdiscovery;
    make;
}

print_usage()
{
    echo "./compile [app | driver | kernel | all]";
    exit 1;
}

if [ "$#" -ne 1 ]; then
    print_usage;
fi

if [ $1 = "app" ]; then
    compile_app;
    exit 0;
fi

if [ $1 = "driver" ]; then
    compile_driver;
    exit 0;
fi

if [ $1 = "kernel" ]; then
    compile_kernel;
    exit 0;
fi

if [ $1 = "all" ]; then
    compile_driver;
    compile_kernel;
    compile_app;
    exit 0;
fi

print_usage;

