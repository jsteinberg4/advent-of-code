package day1

import "testing"

func Test_parseInput(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		text string
		want orderedLocationList
	}{
		{
			name: "Simple case: 1..6, in order",
			text: "1 2\n3 4\n5 6",
			want: orderedLocationList{left: []int32{1, 3, 5}, right: []int32{2, 4, 6}},
		},
		{
			name: "Reversed simple case",
			text: "6 5\n4 3\n2 1",
			want: orderedLocationList{left: []int32{2, 4, 6}, right: []int32{1, 3, 5}},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := parseInput(tt.text)

			if !tt.want.equals(got) {
				t.Errorf("parseInput() = %v, want %v", got, tt.want)
			}
		})
	}
}
