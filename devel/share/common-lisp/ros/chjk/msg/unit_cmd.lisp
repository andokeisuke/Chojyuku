; Auto-generated. Do not edit!


(cl:in-package chjk-msg)


;//! \htmlinclude unit_cmd.msg.html

(cl:defclass <unit_cmd> (roslisp-msg-protocol:ros-message)
  ((vel
    :reader vel
    :initarg :vel
    :type cl:float
    :initform 0.0)
   (deg
    :reader deg
    :initarg :deg
    :type cl:float
    :initform 0.0))
)

(cl:defclass unit_cmd (<unit_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <unit_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'unit_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name chjk-msg:<unit_cmd> is deprecated: use chjk-msg:unit_cmd instead.")))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <unit_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader chjk-msg:vel-val is deprecated.  Use chjk-msg:vel instead.")
  (vel m))

(cl:ensure-generic-function 'deg-val :lambda-list '(m))
(cl:defmethod deg-val ((m <unit_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader chjk-msg:deg-val is deprecated.  Use chjk-msg:deg instead.")
  (deg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <unit_cmd>) ostream)
  "Serializes a message object of type '<unit_cmd>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'deg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <unit_cmd>) istream)
  "Deserializes a message object of type '<unit_cmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'deg) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<unit_cmd>)))
  "Returns string type for a message object of type '<unit_cmd>"
  "chjk/unit_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'unit_cmd)))
  "Returns string type for a message object of type 'unit_cmd"
  "chjk/unit_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<unit_cmd>)))
  "Returns md5sum for a message object of type '<unit_cmd>"
  "68a821851e17ec6fee5da92fea03d8fc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'unit_cmd)))
  "Returns md5sum for a message object of type 'unit_cmd"
  "68a821851e17ec6fee5da92fea03d8fc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<unit_cmd>)))
  "Returns full string definition for message of type '<unit_cmd>"
  (cl:format cl:nil "float64 vel~%float64 deg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'unit_cmd)))
  "Returns full string definition for message of type 'unit_cmd"
  (cl:format cl:nil "float64 vel~%float64 deg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <unit_cmd>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <unit_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'unit_cmd
    (cl:cons ':vel (vel msg))
    (cl:cons ':deg (deg msg))
))
