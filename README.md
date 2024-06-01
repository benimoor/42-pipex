# Pipex

Pipex is a project developed as part of the 42 École curriculum, which involves implementing a simplified version of the shell command-line functionality using pipes.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Description](#project-description)
- [Solution](#solution)
- [Contact](#contact)

## Introduction

Pipex is a program that simulates the functionality of shell pipelines, where the output of one command becomes the input of another command. It allows users to redirect the standard input and output of commands to files or other commands using the pipe (`|`) operator.

## Features

- Execute commands with input/output redirection using pipes.
- Support for multiple commands in a pipeline.
- Error handling and graceful termination.

## Installation

To build and run the pipex project, follow these steps:

1. **Clone the repository**
   ```
   git clone https://github.com/your_username/pipex.git
   cd pipex

    Build the project
    make

## Usage

To use the pipex program, follow this syntax:

    ./pipex file1 cmd1 cmd2 file2

Where:

    file1: Input file whose content will be sent to cmd1.
    cmd1: First command to execute.
    cmd2: Second command to execute.
    file2: Output file where the result of cmd2 will be written.

## Project Description

The pipex project aims to replicate the functionality of shell pipelines using the C programming language. It involves parsing command-line arguments, executing commands with input/output redirection using pipes, and handling errors gracefully.

## Solution

The pipex solution involves the following steps:

    Parse command-line arguments to extract input and output filenames, and commands.
    Create pipes to establish communication between commands.
    Fork child processes to execute commands.
    Redirect input and output of commands using pipes and file descriptors.
    Handle errors and cleanup resources.

## Contact
Erik Grigoryan - ergrigor@student.42yerevan.am
