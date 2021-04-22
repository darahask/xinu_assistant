#define MAX_TODOS 100

struct tcdata{
    uint32 startTime;
    uint32 endTime;
    char message[200];
};

extern struct tcdata tctable[];
extern int32 tcindex;