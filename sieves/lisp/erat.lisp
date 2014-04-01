(defun ERAT(lim)
  (setq sieve (make-array (+ lim 1) :element-type 'bit))
  (loop for i from 2 to (ceiling (sqrt (- (length sieve) 1))) do
    (loop for i2 from (* i 2) to (- (length sieve) 1) by i do
      (setf (bit sieve i2) 1)
    )
  )
  (loop for i from 2 to (- (length sieve) 1) do
    (if (zerop (bit sieve i))
      (print i)
    )
  )
)

(ERAT 1000)
