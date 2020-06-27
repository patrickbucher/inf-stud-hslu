#!/usr/bin/env bash

ffmpeg -i demo.mkv -map 0:v -c:v copy -ss 00:00:10 raw-video.mkv
ffmpeg -i voice-music.mp3 -i raw-video.mkv -map 0:a -map 1:v \
    -metadata title='DeepXRay' -metadata author='Patrick Bucher' -metadata year='2020' -metadata copyright='Music «Microchip» by Jason Farnham (YouTube Audio Library)' \
    -metadata artist='' -metadata album='' -metadata genre='' \
    -t 00:02:00 \
    video-with-music.mkv
ffmpeg -i video-with-music.mkv -pix_fmt yuv420p video-with-music.mp4
