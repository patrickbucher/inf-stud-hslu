(script-fu-register
  "script-fu-draw-new-grid-image" 
  "New Grid Image"
  "Creates a new image with a grid"
  "Patrick Bucher"
  "© 2018 by Patrick Bucher"
  "November 2018"
  ""
  SF-ADJUSTMENT "Width" '(1024 1 4096 1 1 0 1)
  SF-ADJUSTMENT "Height" '(1024 1 4096 1 1 0 1)
  SF-BRUSH "Brush" '("Circle (01)" 100.0 1 0)
  SF-ADJUSTMENT "Spacing" '(10 1 100 1 1 0 1)
  SF-COLOR "Foreground" '(0 0 0)
  SF-COLOR "Background" '(255 255 255)
  SF-TOGGLE "Horizontal" 1
  SF-TOGGLE "Vertical" 0
  SF-TOGGLE "Dashed" 0)

(script-fu-menu-register
  "script-fu-draw-new-grid-image"
  "<Image>/File/Create/New Grid Image")

(define (script-fu-draw-new-grid-image
          width
          height
          brush
          spacing
          foreground
          background
          horizontal
          vertical
          dashed)
  (gimp-context-push)
  (let*
    (
     (image (car (gimp-image-new width height RGB)))
     (layer (car (gimp-layer-new
                   image
                   width
                   height
                   RGBA-IMAGE
                   "grid"
                   100
                   NORMAL-MODE)))
     (layer-width (car (gimp-drawable-width layer)))
     (layer-height (car (gimp-drawable-height layer)))
     (point (cons-array 4 'double)))
    (gimp-context-set-foreground foreground)
    (gimp-context-set-background background)
    (gimp-context-set-brush (car brush))
    (gimp-drawable-fill layer BACKGROUND-FILL)
    (gimp-image-add-layer image layer -1)

    (define (draw-line xa ya xb yb)
      (aset point 0 xa)
      (aset point 1 ya)
      (aset point 2 xb)
      (aset point 3 yb)
      (gimp-paintbrush-default layer 4 point))

    (define (draw-h-line y)
      (cond
        ((< y layer-height)
         (draw-line 0 y layer-width y)
         (draw-h-line (+ y spacing)))))

    (define (draw-v-line x)
      (cond
        ((< x layer-width)
         (draw-line x 0 x layer-height)
         (draw-v-line (+ x spacing)))))

    (define (draw-h-line-dashed x y)
      (cond
        ((< y layer-height)
         (cond
           ((<= x layer-width)
            (draw-line x y (+ x spacing) y)
            (draw-h-line-dashed (+ x (* 2 spacing)) y))
           (else (draw-h-line-dashed 0 (+ y spacing)))))))

    (define (draw-v-line-dashed x y)
      (cond
        ((< x layer-width)
         (cond
           ((<= y layer-height)
            (draw-line x y x (+ y spacing))
            (draw-v-line-dashed x (+ y (* 2 spacing))))
           (else (draw-v-line-dashed (+ x spacing) 0))))))

    (cond
      ((and (eq? horizontal TRUE) (eq? vertical FALSE) (eq? dashed FALSE))
       (draw-h-line spacing))
      ((and (eq? horizontal FALSE) (eq? vertical TRUE) (eq? dashed FALSE))
       (draw-v-line spacing))
      ((and (eq? horizontal TRUE) (eq? vertical TRUE) (eq? dashed FALSE))
       (draw-h-line spacing)
       (draw-v-line spacing))
      ((and (eq? horizontal TRUE) (eq? vertical FALSE) (eq? dashed TRUE))
       (draw-h-line-dashed 0 spacing))
      ((and (eq? horizontal FALSE) (eq? vertical TRUE) (eq? dashed TRUE))
       (draw-v-line-dashed spacing 0))
      ((and (eq? horizontal TRUE) (eq? vertical TRUE) (eq? dashed TRUE))
       (draw-h-line-dashed 0 spacing)
       (draw-v-line-dashed spacing 0)))

    (gimp-display-new image)
    (gimp-context-pop)
    (gimp-displays-flush)))
