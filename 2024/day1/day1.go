package day1

import (
	_ "embed"
	"fmt"
	"log/slog"
	"slices"
	"strconv"
	"strings"
)

//go:embed input.txt
var input string

type orderedLocationList struct {
	left  []int32
	right []int32
}

func (o orderedLocationList) equals(other orderedLocationList) bool {
	return slices.Equal(o.left, other.left) && slices.Equal(o.right, other.right)
}

func parseInput(text string) orderedLocationList {
	var (
		leftLocations  = make([]int32, 0)
		rightLocations = make([]int32, 0)
	)

	slog.Info("start parsing", "input_text", text)

	for _, rowValue := range strings.Split(text, "\n") {
		locations := strings.Fields(rowValue)

		// WARN: Assumes len(locations) == 2; Ignores parse error
		left, _ := strconv.ParseInt(locations[0], 10, 32)
		right, _ := strconv.ParseInt(locations[1], 10, 32)

		leftLocations = append(leftLocations, int32(left))
		rightLocations = append(rightLocations, int32(right))
	}

	// Note: might be more efficient ways to sort. Could maybe just dump into a heap and sort as we compute
	slices.Sort(leftLocations)
	slices.Sort(rightLocations)

	return orderedLocationList{left: leftLocations, right: rightLocations}
}

func Run(a ...string) error {
	fmt.Println("start day1")
	inputs := parseInput(input)
	fmt.Printf("left: %#v\n", inputs.left)
	fmt.Printf("right: %#v\n", inputs.right)
	return nil
}
