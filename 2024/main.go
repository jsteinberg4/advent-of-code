package main

import (
	"errors"
	"flag"
	"fmt"
	"os"

	"github.com/jsteinberg4/advent-of-code-2024/day1"
)

var dayMap = map[string]func(a ...string) error{
	"day1": day1.Run,
}

func main() {
	flag.Parse()
	day := flag.Arg(0)

	if fn, ok := dayMap[day]; ok {
		fn(flag.Args()[1:]...)
	} else {
		fmt.Print(errors.New("Solution not yet registered for day: " + day))
		os.Exit(1)
	}
}
