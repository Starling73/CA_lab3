# Laboratory work #3

Command line tool for task scheduling.

## Usage:

### --help (-h)

Shows the manual for the program.

#### Example

- ./schdl --help

### --task (-t)

Inputs a name of .bat file with task to be scheduled.

#### Arguments

- **$1** (string): The .bat file name.

#### Example

- ./schdl --ttask.bat

### --postpone (-p)

Postpones the task for the specified time in minutes.

#### Arguments

- **$1** (number): Time in minutes.

#### Example

- ./schdl --ttask.bat --postpone 60

### --interval (-i)

Inputs an interval to repeat a task with the given interval.

#### Arguments

- **$1** (number): Time in minutes.

#### Example

- ./schdl --ttask.bat --interval 60
