import face_recognition
import cv2


def face_rec():
    # write encodings to txt
    fp = open("face_encoding.txt", "w+")
    # load image encodings
    print("Model Initialized")
    s_0 = input("图片编号：\n")
    s1_image = face_recognition.load_image_file("C:/Users/70/Desktop/test/" + s_0 + ".jpg")
    s1_face_encoding = face_recognition.face_encodings(s1_image)[0]
    s1_list = s1_face_encoding.tolist()
    print("running")

    for ele in s1_list:
        fp.write(" " + str(ele))

    fp.close()

    '''
    # using camera to recognize the face
    video_capture = cv2.VideoCapture(0)
    # create arrays of known face encodings and their names
    known_face_encodings = [
        s1_face_encoding
    ]
    known_face_names = [
        "me"
    ]
    # Initialize some variables
    face_locations = []
    face_encodings = []
    face_names = []
    process_this_frame = True
    while True:
        ret, frame = video_capture.read()
        small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
        rgb_small_frame = small_frame[:, :, ::-1]
        if process_this_frame:
            face_locations = face_recognition.face_locations(rgb_small_frame)
            face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)
            face_names = []
            for face_encoding in face_encodings:
                matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
                name = "Unknown"
                if True in matches:
                    first_match_index = matches.index(True)
                    name = known_face_names[first_match_index]
                face_names.append(name)
        process_this_frame = not process_this_frame
        for (top, right, bottom, left), name in zip(face_locations, face_names):
            # Scale back up face locations since the frame we detected in was scaled to 1/4 size
            top *= 4
            right *= 4
            bottom *= 4
            left *= 4
            cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)
            cv2.rectangle(frame, (left, bottom - 35), (right, bottom), (0, 0, 255), cv2.FILLED)
            font = cv2.FONT_HERSHEY_DUPLEX
            cv2.putText(frame, name, (left + 6, bottom - 6), font, 1.0, (255, 255, 255), 1)
        cv2.imshow('Video', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    video_capture.release()
    cv2.destroyAllWindows()
    '''
    return

# face_rec()
