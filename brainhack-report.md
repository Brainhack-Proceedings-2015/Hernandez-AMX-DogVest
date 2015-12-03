---
event: '2015 Brainhack Americas (MX)'

title:  'Optimized implementations of voxel-wise degree centrality and local functional connectivity density mapping in AFNI'

author:

- initials: LVC
  surname: Cuaya
  firstname: Laura V.
  email: lauveri.rozen@gmail.com
  affiliation: aff1
  corref: aff1
- initials: EAM
  surname: Morales
  firstname: Edgar A.
  email: edalvmor@yahoo.com.mx
  affiliation: aff1
- initials: RH
  surname: Hernandez
  firstname: Raul
  email: sevenedenr@gmail.com
  affiliation: aff1

affiliations: 

- id: aff1
  orgname: 'Instituto de Neurobiología"
  street: Boulevard Juriquilla 3001
  postcode: 76230
  city: Queretaro
  state: Queretaro
  country: Mexico

url: https://github.com/nekrum/DogVest

coi: None

acknow: We would like to thank the organizers and attendees of Brainhack MX and to the Instituto de Neurobiología. Specially to Fernando Barrios Alvarez for the invitation and the support on the realization of the project.
Laura V. Cuaya, Raul Hernández and Edgar Morales are a doctoral students from Programa de Doctorado en Ciencias Biomédicas, Universidad Nacional Autónoma de México (UNAM) and received fellowship 407590, 409258 and 215702 from CONACYT.  

contrib: RH wrote the software, EAM deployed report, and LVC and RH wrote the report.
  
bibliography: brainhack-report

gigascience-ref: REFXXX
...



# Introduction

In dogs, the perception of an important stimulus can be related to 
physiological changes such as the heart rate (e.g., in socioemotional situations
 with humans \cite{Palestrini200575} or dogs \cite{Siniscalchi20132279} ) and the movement of their tail (e.g., tail-wagging
 has a bias that depends on the nature of the stimulus, a bias to the left is 
related to a withdrawal tendency and a bias to the right is related to an aproach
 tendency \cite{Quaranta2007R199} ). 

Altough heart rate and the tail movement are important gateways to understand
dog’s cognition, just a few studies report these variables. Perhaps this is
related to the difficulty of obtaining records of these variables in natural
enviroments (e.g., parks), the elevated cost of a commercial data adquisition
hardware (around $5,000 USD)  or by inexistence of a tail-movement
registering device. For these reasons, the goal of this brainhack project is to
design and build a low cost device able to register the heart rate and changes
in the tail movement in dogs, both in laboratory and in free movement
conditions.


# Approach

We decided to base our design in arduino hardware for its accessibility and broad use. The materials are detailed in the \ref{materialstable}.

\begin{table*}[t!]
\caption{\label{materialsttable} Materials and cost. The table shows most of the materials used and their approximated cost with a local provider. Other materials were used but their cost is negligible.}
\begin{tabular}{l l}
 \hline\noalign{\smallskip}
   Materials  & Aproximated cost (in USD) \\
    \hline\noalign{\smallskip}
  Arduino UNO rev3   				& 20    \\
  EKG-EMG-shield from Olimex with electrodes    & 48    \\
  Vibration sensor from phidgets    		& 11    \\
  9v rechargeable battery    			& 7	\\
  SD Card Reader module ARM MCU    		& 1.2   \\
  Total    					& 87.2  \\
  \noalign{\smallskip}\hline
\end{tabular}
\end{table*}

We designed and 3d printed a PLA case to contain the circuit. The case has a
slot to add a strap to fix the device on the dogs back. The program for the
arduino and the model for the case can be downloaded from the GitHub (scripts directory)
repository of the project.

In order to asses if the device could reliably get readings from a dog, we
tested it in three phases: baseline, stimulation/no-stimulation and free
movement. All phases lasted two minutes and were repeated twice on two dogs. In
both, baseline and stimulation/no-stimulation, the dog stayed in sphinx position
without movement restrictions but under the command “stay”. The
stimulation/no-stimulation phase consisted in three interleaved repetitions of
two types of conditions, stimulation and no-stimulation, each repetition lasted
20 s. In the stimulation condition the dog owner showed the dog a treat and
mention the dog’s name. In the free movement condition, the dog walked down a
street without any specific command.

# Results

In the stimulation/no-stimulation phase a  Wilcoxon Signed Rank Test revealed
statistically significant differences (p < 0.05) between the beats per minute,
beat amplitude and the tail movement amplitude \ref(centfig}.

\begin{figure}[h!]
  \includegraphics[width=.47\textwidth]{centrality_plot}
  \caption{\label{centfig}
The results shown were obtained from two dogs under two consecutive conditions. Stimulation and No-stimulation. In panels A), B) and C), the colors represent the conditions. The panel A) represents the standard deviation from the mean of the heart beat amplitude. The panel B) represents the change on the beats per minute on both conditions minus a baseline registered directly from each dog. The vertical lines represent the standard error. The panel C) represents the standard deviation from the mean of the tail movement. The panel D) shows one of the registered dogs wearing the device.
}
\end{figure}

By matching the data collected with observations of the movement of the tail, we
notice that the data reflects the position of the tail but its resolution
depended on the position of the electrode.

The data acquire from the free movement condition was affected by the movement
and didn’t seem reliable for testing.

# Conclusions

We were able to build and test a non-invasive low cost device with the capacity
to register the heart rate and the tail movement of dogs. We consider that the
addition of a movement sensor could provide additional data to reduce the change
on the signal due to movement.

This device can be integrated in future research on dog’s cognition. It can also
be used in shelters and homes to easily measure the responses that dogs present
to different sets of stimuli; for example, when a dog is left alone in its house
and shows stress (i.e. increased heart rate, preferential tail movement to the
left) the dog’s carer could make changes in the environment to increase the
well-being of the dog.


The low cost and the easy access to the materials needed to build the device
make it a feasible option to study dog cognition. The results showed that the
device could be used to distinguish between two different stimulation
conditions.
