# Poco Project Template
#### Saving you from the annoyances of setting up your project...

Often find myself fiddling with CMake/Docker, trying to get a basic project started before writing my first lines of interesting code. So I decided to create this template to save myself (and anyone in my shoes) the time it takes to get all the dependencies sorted out.

## Setup with CLion

We will follow the instructions provided on [Jetbrains' official blog](https://blog.jetbrains.com/clion/2020/01/using-docker-with-clion/) to get our development environment setup. The new Docker toolchain suffers from a few limitations, so we will stick with the Remote Host trick for now. To summarize:

### 0. Prerequisites

Ensure you have CLion installed. As well as Docker installed and running.

### 1. Clone the Project

Clone this project:
```bash
git clone https://github.com/MQumairi/poco-template.git
```

Then open it with CLion.

### 2. Build the Docker Image

The variation of the Docker Image provided with this project includes dependencies you'll need for Poco. 

To build the image, execute the following command, while ensuring present working directory is this project's root:
```bash
docker build -t mqumairi/poco_dev -f Dockerfile.dev .
```
This may take a few minutes.

> Tip: feel free to rename the image from `mqumairi/poco_dev` to whatever else. Just make sure you mirror those changes in the next step.

### 3. Run the Docker Image

Run your image. Make sure you at least expose port 22 of your container so that you may be able to SSH into it. In addition to this, expose any other ports that your project may need. In our case, since the default project builds a server listening on port 7777, we will expose this port as well:
```bash
docker run -d --cap-add sys_ptrace -p 2222:22 -p 7777:7777 --name poco_dev mqumairi/poco_dev
```

### 4. Create New Toolchain

For the rest of the steps we follow the instructions showcased in the official [Jetbrains video](https://www.youtube.com/watch?v=h69XLiMtCT8) starting from minute 3:15. The only deviation from the video, is when you insert credentials to SSH into container, use the following username/password combination instead of what is supplied in the video:

- **username**: root
- **password**: root

Feel free to watch the video and skip the rest of the following steps. 

But if you prefer to read on...

Open CLion preferences. From the side bar, under `Build, Execution, Deployment`, select `Toolchains`.

Click on the tiny `+`, top left of the main window. Add a new `Remote Host`. Give it any name you want.

Next to the `Credentials` field, press on the small gear icon. This will pop up a new window for you to insert your container’s credentials. In this new window, click on the tiny `+` located top left. Fill in the form.

- **Host:** localhost
- **Port:** 2222
- **User name**: root
- **Password**: root


Leave everything else as default. Press on “OK” to close the window, then press on “Apply” to create your new Toolchain.

### 5. Apply Toolchain to CMake Profile

While still in CLion preferences, from the side bar, under `Build, Execution, Deployment`, select `CMake`.

Select the active profile. Change its *Toolchain* to the toolchain you just created (the name you chose for the toolchain you created in the previous step, should be available from the drop down menu).

Press OK to save and close preferences.

### 6. Final Touches

At this point, you should be able to run your project as expected! But if you experience any problems...

You may need to resync your files with the container. From the main menu bar, select `Tools` -> `Resync with Remote Hosts`.

You may also benefit from rebuilding your CMake project. From the main menu bar, select `Tools` -> `CMake` -> `Reload CMake Project`.

