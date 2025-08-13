The process for aligning a character's bones using torque.

Per Bone:
  1. Calculate Target and Current Up + Forward Vectors for Bone (CurrentUp,CurrentForward,TargetUp,TargetForward) in the bone's local space
  2. Calculate distance from Target -> Current in Radians:

      a). Normalize Direction vectors for Target and Current
    
      b). Cross Product Normalized Vectors
    
      c). Dot product that vector with the plane you want to apply torque on (ex: 0,0,1 if you want to apply torque on the bone's local Z axis) - this is our Y in Atan2
    
      d). Dot product our normalized Current & Target direction vectors - this is our X for Atan2
    
      e). Result of Atan2 on Y and X gives us the amount of radians we need to get Current -> Target on the desired axis
    
      f). Repeat per axis. Use target Up for Left / Right / Forward / Back lean and target Forward for twist.
    
      g). Add vectors together to get our the direction in radians we need to apply torque on each axis.


  5.  Convert torque vector from local space to world space (axis will be wrong otherwise)
