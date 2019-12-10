
(cl:in-package :asdf)

(defsystem "chjk-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "unit_cmd" :depends-on ("_package_unit_cmd"))
    (:file "_package_unit_cmd" :depends-on ("_package"))
    (:file "vw_cmd" :depends-on ("_package_vw_cmd"))
    (:file "_package_vw_cmd" :depends-on ("_package"))
  ))