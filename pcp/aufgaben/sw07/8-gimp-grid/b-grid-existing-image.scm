(script-fu-register
  "script-fu-draw-grid-existing" 
  "Grid on Existing Image"
  "Adds a grid to an existing image"
  "Patrick Bucher"
  "© 2018 by Patrick Bucher"
  "November 2018"
  ""
  SF-IMAGE "Image" 0
  SF-BRUSH "Brush" '("Circle (01)" 100.0 1 0)
  SF-ADJUSTMENT "Spacing" '(10 1 100 1 1 0 1)
  SF-COLOR "Color" '(0 0 0)
  SF-TOGGLE "Horizontal" 1
  SF-TOGGLE "Vertical" 0
  SF-TOGGLE "Dashed" 0)

(script-fu-menu-register
  "script-fu-draw-grid-existing"
  "<Image>/File/Create/Grid on Image")

(define (script-fu-draw-grid-existing
          image
          brush
          spacing
          color
          horizontal
          vertical
          dashed)
  (gimp-context-push)
  (let*
    (
     (width (car (gimp-image-width image)))
     (height (car (gimp-image-height image)))
     (layer (car (gimp-layer-new image
                                 width
                                 height
                                 RGBA-IMAGE
                                 "grid"
                                 100
                                 NORMAL-MODE)))
     (point (cons-array 4 'double)))
    (gimp-context-set-foreground color)
    (gimp-context-set-brush (car brush))
    (gimp-drawable-fill layer TRANSPARENT-FILL)
    (gimp-image-add-layer image layer -1)

    (define (draw-line xa ya xb yb)
      (aset point 0 xa)
      (aset point 1 ya)
      (aset point 2 xb)
      (aset point 3 yb)
      (gimp-paintbrush-default layer 4 point))

    (define (draw-h-line y)
      (cond
        ((< y height)
         (draw-line 0 y width y)
         (draw-h-line (+ y spacing)))))

    (define (draw-v-line x)
      (cond
        ((< x width)
         (draw-line x 0 x height)
         (draw-v-line (+ x spacing)))))

    (define (draw-h-line-dashed x y)
      (cond
        ((< y height)
         (cond
           ((<= x width)
            (draw-line x y (+ x spacing) y)
            (draw-h-line-dashed (+ x (* 2 spacing)) y))
           (else (draw-h-line-dashed 0 (+ y spacing)))))))

    (define (draw-v-line-dashed x y)
      (cond
        ((< x width)
         (cond
           ((<= y height)
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

    (gimp-context-pop)
    (gimp-displays-flush)))
