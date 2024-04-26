//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element in umgekehrter Reihenfolge.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Findet ein Listenelement mit der angegebenen Matrikelnummer.
 * 
 * Diese Methode durchsucht die Liste nach einem Listenelement, dessen Matrikelnummer
 * mit der angegebenen Matrikelnummer übereinstimmt.
 * 
 * @param matNr Die Matrikelnummer des gesuchten Listenelements.
 * @return Ein Zeiger auf das gefundene Listenelement oder nullptr, wenn kein
 *         entsprechendes Element gefunden wurde.
 */
ListenElement* Liste::findElement(unsigned int matNr)
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        if(cursor->getData().getMatNr() == matNr)
        {
            return cursor;
        }
        cursor = cursor->getNext();
    }
    return nullptr;
}
/**
 * @brief Löscht ein Element aus der Liste anhand der Matrikelnummer.
 * 
 * Diese Funktion sucht nach einem Element mit der angegebenen Matrikelnummer und löscht es aus der Liste, falls es gefunden wird.
 * @param matNr Die Matrikelnummer des zu löschenden Elements.
 */
void Liste::deleteElement(unsigned int matNr)
{
    ListenElement* cursor = findElement(matNr);
    if(cursor == front)
    {
        popFront();
    }
    else if(cursor == back)
    {
        back = back->getPrev();
        back->setNext(nullptr);
        delete cursor;
    }
    else
    {
        cursor->getPrev()->setNext(cursor->getNext());
        cursor->getNext()->setPrev(cursor->getPrev());
        delete cursor;
    }
}
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}