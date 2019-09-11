/*
 * Copy me if you can.
 * by 20h
 */

#ifndef ARG_H__
#define ARG_H__

/* store the program's name */
extern char *argv0;

/*
 * Use `main(int argc, char *argv[])'.
 * To parse single-letter flags or options (with EARGF()), use the following
 * construct:
 *
 *          ARGBEGIN {
 *          case 'a':
 *             // use the flag
 *             break;
 *          case 'b':
 *             // use the flag
 *             break;
 *          } ARGEND;
 *
 */
#define ARGBEGIN	for (argv0 = *argv, argv++, argc--;                     \
					     argv[0] && argv[0][0] == '-' && argv[0][1];        \
					     argc--, argv++) {                                  \
				            char argc_;                                     \
				            char **argv_;                                   \
				            int brk_;                                       \
				            if (argv[0][1] == '-' && argv[0][2] == '\0') {  \
				            	argv++;                                     \
				            	argc--;                                     \
				            	break;                                      \
				            }                                               \
				            int i_;                                         \
				            for (i_ = 1, brk_ = 0, argv_ = argv;            \
				            		argv[0][i_] && !brk_;                   \
				            		i_++) {                                 \
				            	if (argv_ != argv)                          \
				            		break;                                  \
				            	argc_ = argv[0][i_];                        \
				            	switch (argc_)

#define ARGEND		} \
			    }

/* retrieve the current `argc' (i.e. `argc_') */
#define ARGC()      argc_

/* retrieve an option's parameter or error */
#define EARGF(x)	((argv[0][i_+1] == '\0' && argv[1] == NULL) ? \
				        ((x), abort(), (char *)0) :               \
				        (brk_ = 1, (argv[0][i_+1] != '\0') ?      \
					        (&argv[0][i_+1]) :                    \
					        (argc--, argv++, argv[0])))

/* retrieve an option's parameter or return NULL */
#define ARGF()		((argv[0][i_+1] == '\0' && argv[1] == NULL) ? \
				        (char *)0 :                               \
				        (brk_ = 1, (argv[0][i_+1] != '\0') ?      \
					        (&argv[0][i_+1]) :                    \
					        (argc--, argv++, argv[0])))

#endif
