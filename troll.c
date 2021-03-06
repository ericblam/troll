#include <stdio.h>
#include <string.h>
#include "commands.h"

/* This gets printed out when troll is run with no arguments */
const char *help_text =
    "usage: troll <command> [<args>]\n\n"
    "Troll commands:\n"
    "\tinit\tCreate a new troll repository\n"
    "\thelp\tGet help on commands\n"
    "\tadd\tAdd files to the working directory\n"
    "\tls-files\tView what files have been tracked\n"
    "\tstatus\tView status of repo... do not use\n"
    "\tcommit\tSave the tree/index to a point to go back to\n"
    "\tlog\tView commit history\n"
    "\tcheckout\tGo back to a previous commit\n"
    "\tface\tGet a surprise\n"
    "\n"
    "See 'troll help <command>' for more information on a specific command.";

struct cmd_struct {
    const char *cmd;
    int (*func)(int argc, const char *argv[]);
};

void print_help_text() {
    printf("%s\n", help_text);
}

int run_command(int argc, const char *argv[]) {
    struct cmd_struct commands[] = {
        { "help", cmd_help },
        { "init", cmd_init },
	{ "face", cmd_face },
	{ "add", cmd_add },
	{ "ls-files", cmd_ls_files },
	{ "status", cmd_status },
	{ "commit", cmd_commit },
	{ "log", cmd_log },
	{ "checkout",cmd_checkout },
    };

    const char *cmd = argv[0];

    int i;
    for (i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
        if (strcmp(commands[i].cmd, cmd) == 0) {
            return commands[i].func(argc, argv);
        }
    }

    printf("troll: '%s' is not a troll command.\n", cmd);
    return 1;
}

int main(int argc, const char *argv[])
{
    if (argc == 1) {
        print_help_text();
        return 1;
    }
    argc--;
    argv++; // The command name is now the first argument
    return run_command(argc, argv);
}
