# Intel(R) oneAPI Data Analytics Library Spark\* Samples

Spark\* samples for the Intel(R) oneAPI Data Analytics Library (oneDAL) are designed to show how to use this library on the Spark cluster in a Scala application.

Unzip the archive with oneDAL samples to your working directory (`<sample_dir>`).

## System Requirements
You can use oneDAL Spark samples on Linux\* and macOS\* operating systems. For a list of oneDAL hardware and software requirements, refer to release notes for the version of oneDAL you are using.

### Spark implementations against which oneDAL has been validated:
- Spark 2.0.0
### Scala samples validated on:
- Scala 2.11.11

**Note:** oneDAL is expected to work on many more Spark distributions as well. Let us know if you have any troubles with the distribution you are using.

## Preparation Before Build and Run
### Setting Up the Build Environment 
Before you build the sample, you must set certain environment variables that define the location of related libraries. The oneDAL includes the `vars` scripts that you can run to set environment variables:

- On Linux\*, you can find the `vars.sh` shell script at `<install-dir>\compilers_and_libraries_xxxx.x.xxx\linux\daal\bin:
source vars.sh {ia32|intel64}`
- On macOS\*, you can find the `vars.sh` shell script at `<install-dir>\compilers_and_libraries_xxxx.x.xxx\mac\daal\bin:
source vars.sh`

For more information about setting environment variables and configuring oneDAL, refer to Getting Started guides for the library.

## Build and Run Instructions
### On Linux\* and macOS\*
To build oneDAL Spark Scala samples, go to the Scala Spark samples directory:

```
cd <sample_dir>/scala/spark
```

Execute the `./launcher.sh {ia32|intel64}` script to run the following algorithms on your Spark cluster:

- K-Means clustering;
- Principal component analysis (PCA) using the correlation method;

You can manage the list of running samples by changing the `Spark_samples_list` variable in the `./launcher.sh` script.

From the `{ia32|intel64}` parameters, select the one that matches the architecture parameter you provided to the `vars.sh` script. If no parameters are defined for the `make` command, the Intel(R) 64 architecture is used by default.

For each algorithm, the results are stored in the `/_results/<sample_name>/<sample_name>.res` file.

## Notices and Disclaimers

Performance varies by use, configuration and other factors. Learn more at www.Intel.com/PerformanceIndex???.  

No product or component can be absolutely secure. 

Your costs and results may vary.

Intel technologies may require enabled hardware, software or service activation.

**&copy; Intel Corporation**. Intel, the Intel logo, and other Intel marks are trademarks of Intel Corporation or its subsidiaries.  Other names and brands may be claimed as the property of others.

\*Other names and brands may be claimed as the property of others.
