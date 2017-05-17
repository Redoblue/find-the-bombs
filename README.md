# find-the-bombs

# Run

You can find a previously compiled executable file in the *cmake-build-debug* folder, run it with some flags:

```
./find-the-bombs -file=nameofvideo.avi -ndpp=50 -std=10.0 -showall=true
```
where flags mean:
```
-file       file name of the video you want to track            REQUIRED
-ndpp       number of particles for each object                 OPTIONAL
-std        standard deviation of transition model              OPTIONAL
-showall    whether to show all the particles or the best one   OPTIONAL
```
you can also use **-help** flag to see all the options.

# Explaination

Our model is processed by the commander, who controls all the processed including **sample**,**transit** and **resample**. For each bomb (object) to find (track), the commander will assign one police to handle it. And each of our police can take many dogs (particles) with him to make things easier.

feel free to test! ^_^
