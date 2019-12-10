;; Auto-generated. Do not edit!


(when (boundp 'chjk::unit_cmd)
  (if (not (find-package "CHJK"))
    (make-package "CHJK"))
  (shadow 'unit_cmd (find-package "CHJK")))
(unless (find-package "CHJK::UNIT_CMD")
  (make-package "CHJK::UNIT_CMD"))

(in-package "ROS")
;;//! \htmlinclude unit_cmd.msg.html


(defclass chjk::unit_cmd
  :super ros::object
  :slots (_vel _deg ))

(defmethod chjk::unit_cmd
  (:init
   (&key
    ((:vel __vel) 0.0)
    ((:deg __deg) 0.0)
    )
   (send-super :init)
   (setq _vel (float __vel))
   (setq _deg (float __deg))
   self)
  (:vel
   (&optional __vel)
   (if __vel (setq _vel __vel)) _vel)
  (:deg
   (&optional __deg)
   (if __deg (setq _deg __deg)) _deg)
  (:serialization-length
   ()
   (+
    ;; float64 _vel
    8
    ;; float64 _deg
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _vel
       (sys::poke _vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _deg
       (sys::poke _deg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _vel
     (setq _vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _deg
     (setq _deg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get chjk::unit_cmd :md5sum-) "68a821851e17ec6fee5da92fea03d8fc")
(setf (get chjk::unit_cmd :datatype-) "chjk/unit_cmd")
(setf (get chjk::unit_cmd :definition-)
      "float64 vel
float64 deg

")



(provide :chjk/unit_cmd "68a821851e17ec6fee5da92fea03d8fc")


