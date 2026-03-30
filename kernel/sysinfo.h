struct sysinfo {
    uint64 freemem; // Number of free memory bytes
    uint64 nproc; // Number of processes with a state other than UNUSED
    uint64 nopenfiles; // Number of open files in the entire system
};
