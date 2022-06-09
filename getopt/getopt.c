#include <err.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

static struct option opt_longue[] = { { "artist", required_argument, NULL,
                                        'a' },
                                      { "year", required_argument, NULL, 'y' },
                                      { 0, 0, 0, 0 } };

int display(char *artist, char *year, char *song)
{
    if (song == NULL || song == year || song == artist)
    {
        warnx("missing song title");
        return 1;
    }
    printf("Song name: %s\n", song);
    if (artist != NULL)
        printf("By: %s\n", artist);
    if (year != NULL)
        printf("Year: %s\n", year);
    return 0;
}

int main(int pre, char **argv)
{
    char *artist = NULL;
    char *year = NULL;
    char *song = NULL;
    int tmp;
    if (pre == 1)
        return 1;
    while ((tmp = getopt_long(pre, argv, "a:y:", opt_longue, NULL)) != -1)
    {
        switch (tmp)
        {
        case 'a':
            if (optarg == NULL)
            {
                warnx("option '--artist' requires an argument\n");
                return 1;
            }
            artist = optarg;
            break;
        case 'y':
            if (optarg == NULL)
            {
                warnx("option '--year' requires an argument\n");
                return 1;
            }
            year = optarg;
            break;
        }
    }
    while (optind + 1 < pre)
        optind++;
    song = argv[optind];
    return display(artist, year, song);
}
