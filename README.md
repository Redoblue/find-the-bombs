# find-the-bombs
Find bombs (track objects) with particle filter tracking technique.

# Set environment
The following three libs are required to set up the environment.
- gsl
- gflags
- opencv

You can install the first two of them on ubuntu by simply run the following commands.
```shell
sudo apt-get install libgsl-dev libgflags-dev
```
As for **OpenCV**, you can refer to this [page](http://www.jianshu.com/p/e12c5d993984). 
BTW, you also need cmake with version older than 3.7.

---

# Run
## how to run
You can find a previously compiled executable file named **find-the-bombs** in the folder, run it with some flags:

```
./find-the-bombs -file=Ball.avi -ndpp=50 -std=10.0 -showall=true
```
where flags mean:
```
-file       file name of the video you want to track            REQUIRED
-ndpp       number of particles for each object                 OPTIONAL
-std        standard deviation of transition model              OPTIONAL
-showall    whether to show all the particles or the best one   OPTIONAL
```
you can also use **-help** flag to see all the options.

## keyboard control
while runing the file,
- press **Enter** to confirm selection.
- press **Space Bar** to quit.

## compile for yourself
If you want to compile it yourself, just follow the following steps:
go to the *find-the-bombs* folder, run 
```
cmake .
```
and then run
```
make
```
all done.

---

# Explaination
Our model is processed by the commander, who controls all the processes including **sample**,**transit** and **resample**. For each bomb (object) to find (track), the commander will assign one police to handle it. And each of our police can take many dogs (particles) with him to make things easier.

This work takes me days to finish, it's actually not an easy job for me, so *feel free to test!*  ^_^
